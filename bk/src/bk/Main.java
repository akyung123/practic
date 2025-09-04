package bk;

import java.util.Scanner;

public class Main {
    // 퀵 정렬로 구현
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        int[] num = new int[n];
        for(int i = 0; i < n; i++) {
            num[i] = sc.nextInt();
            sc.nextLine();
        }
        quickSort(num, 0, n - 1);

        for(int i = 0; i < n; i++) {
            System.out.println(num[i]);
        }
    }

    public static void quickSort(int[] num, int low, int high) {
        if (low < high) {
            int pi = partition(num, low, high);
            quickSort(num, low, pi - 1);
            quickSort(num, pi + 1, high);
        }
    }
    public static int partition(int[] num, int left, int right) {
        int pivot = num[left];
        int low = left + 1;
        int high = right;

        while(low <= high) {
            while (low <= right && num[low] < pivot) low++;
            while (high >= left && num[high] > pivot) high--;
            if (low <= high) {
                int temp = num[low];
                num[low] = num[high];
                num[high] = temp;
                low++;
                high--;
            }
        }
        int temp = num[left];
        num[left] = num[high];
        num[high] = temp;

        return high;
    }
}
