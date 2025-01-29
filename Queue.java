import java.util.Scanner;

public class Q3{
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.println("Enter the Array size: ");
        int size=input.nextInt();
        int[] A = new int[size];
        int front=-1;
        int rear=-1;
        while(true)
        {
            System.out.println("What you want?");
            System.out.println("1.Enqueue.");
            System.out.println("2.Denqueue.");
            int op=input.nextInt();
            if(op==1)
            {
                if((front == 0 && rear == size - 1) || (front==rear+1))
                {
                    System.out.println("OverFlow");
                }
                else if(front == -1)
                {
                    front = 0;
                    rear=0;
                    System.out.println("Enter the value: ");
                    int q=input.nextInt();
                    A[rear]=q;
                }
                else if(rear == size - 1 && front != 0)
                {
                    rear = 0;
                    System.out.println("Enter the value: ");
                    int q=input.nextInt();
                    A[rear]=q;
                }
                else 
                {
                    rear++;
                    System.out.println("Enter the value: ");
                    int q=input.nextInt();
                    A[rear]=q;
                }
                
            }
            else if(op==2)
            {
                if(front == -1)
                {
                    System.out.println("Queue is Empty.");
                }
                else if(front == rear)
                {
                    System.out.println("Dequeue Element: "+A[front]);
                    front=-1;
                    rear=-1;
                }
                else if(front==size-1)
                {
                    System.out.println("Dequeue Element: "+A[front]);
                    front=0;
                }
                else
                {
                    System.out.println("Dequeue Element: "+A[front]);
                    front++;
                }
            }
        }
    }
}