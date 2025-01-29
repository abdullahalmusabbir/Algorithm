import java.util.Scanner;

public class Insert {
    public static void main(String[] args) {
        System.out.println("Enter the array size: ");
        Scanner input=new Scanner(System.in);
        int n=input.nextInt();
        int[] a = new int[n];

        System.out.println("Enter the array: ");
        for(int i=0;i<n;i++)
        {
            a[i]=input.nextInt();
        }

        int temp;
        for(int i = 1;i<n;i++)
        {
            temp=a[i];
            int j=i-1;
            while (temp < a[j] && j >= 0) {
                a[j + 1] = a[j];
                --j;
              }
              a[j + 1] = temp;
        }

        System.out.println("After Sorting: ");
        for(int i=0;i<n;i++)
        {
            System.out.println(a[i]+", ");
        }
    }
    
}
