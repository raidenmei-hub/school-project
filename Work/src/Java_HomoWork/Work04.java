package Java_HomoWork;
import java.util.Scanner;
public class Work04 {
    public static void jishu_oushu(int a){
        if(a%2==0){
            System.out.println("这个数是偶数");
        }
        else if(a%2!=0){
            System.out.println("这个数是奇数");
        }
    }
    public static int mAx(int a,int b){
        int max=a;
        if(b>max){
            max=b;
        }
        return max;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("执行作业一。。。");
        int a= sc.nextInt();
        jishu_oushu(a);
        System.out.println("执行作业二。。。");
        int i= sc.nextInt();
        int j=sc.nextInt();
        System.out.println("最大值为："+mAx(i,j));
        sc.close();
    }
}
