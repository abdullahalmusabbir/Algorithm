import java.util.Scanner;

import javax.lang.model.util.ElementScanner14;

public class Stack1 {
    public static void main(String[] args) {
        Scanner input= new Scanner(System.in);
        System.out.println("Enter the Array size: ");
        int n=input.nextInt();
        int[] A=new int[n];
        
        int top=-1;
        while(true)
        {
            System.out.println("What you want?\n1.Push.\n2.Pop\n3.Check(is emty)\n4.Check(is full)\n5.Size\n6.Top\n7.isPeek.\n8.Full Stack\n9.Exits");
            int m=input.nextInt();
            if(m==1)
            {
                if(top==n-1)
                {
                    System.out.println("Stack is full");
                }
                else
                {
                    System.out.println("Enter the Push number : ");
                    int x=input.nextInt();
                    top++;
                    A[top]=x;
                }
            }
            else if(m==2)
            {
                if(top==-1)
                {
                    System.out.println("Stack is Emty");
                }
                else
                {
                    System.out.println(A[top]+" Pop Done.");
                    top--;

                }
            }
            else if(m==3)
            {
                if(top==-1)
                {
                    System.out.println("Stack is Emty.");
                }
                else 
                {
                    System.out.println("Stack is not Emty");
                }
            }
            else if(m==4)
            {
                if(top==n-1)
                {
                    System.out.println("Stack is full.");
                }
                else
                {
                    System.out.println("Stack is not full.");
                }
            }
            else if(m==5)
            {
                System.out.println("Size: "+(top+1));
            }
            else if(m==6)
            {
                if(top==-1)
                {
                    System.out.println("Emty........");
                }
                else
                {
                    System.out.println("Top: "+A[top]);
                }
            }
            else if(m==7)
            {
                if(top==-1)
                {
                    System.out.println("Emty........");
                }
                else
                {
                    System.out.println("Peek: "+A[top]);
                }
            }
            else if(m==8)
            {
                System.out.print("Values of The Stack: ");
                for(int i=0;i<=top;i++)
                {
                    System.out.print(A[i]+",");
                }
                
            }
            else if(m==9)
            {
                break;
            }
            else
            {
                continue;
            }
        }
    }
    
}
