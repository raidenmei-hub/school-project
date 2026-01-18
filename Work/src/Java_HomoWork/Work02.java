package Java_HomoWork;
import java.util.Scanner;
public class Work02 {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("请输入两个数字：");
        int i,j;
        while(true){
            if(sc.hasNextInt()){
                i=sc.nextInt();
                j=sc.nextInt();
                break;
            }
            else{
                System.out.println("输入的不是整数，请重新输入");
            }
        }
        //最大公约数
          for(int k=Math.max(i,j);;k--){
              if(j%k==0&&i%k==0){
                  System.out.println("两数的最大公约数为"+k);
                  break;
              }
          }
        //最小公倍数
        for(int k=Math.max(i,j);;k++){
            if(k%i==0&&k%j==0){
                System.out.println("两数的最小公倍数为"+k);
                break;
            }
        }
        int number;
        while(true){
            if(sc.hasNextInt()){
                number=sc.nextInt();
                break;
            }
            else{
                System.out.println("输入的不是整数，请重新输入：");
            }
        }
        //逆序输出
        if(number==0){
            System.out.println(number);
        }
        if(number<0){
            System.out.print("-");
            number=-number;
        }
        int digital,h=0,sum=0;
        int[] arr;
        arr=new int[100];
        while (number > 0) {
            digital=number%10;
            System.out.print(digital);
            number=number/10;
            arr[h]=digital;
            h++;
            if(h>99){
                System.out.println("超过系统内存；");
            }
        }
        System.out.print("\n");
        //位数求和
        for(h=0;h<100;h++){
                sum += arr[h];
        }
        System.out.println(sum);
        //1+11+111+1111...
        int m=0;
        sum=0;
        for(int k=0;k<6;k++){
            m=m*10+1;
            arr[k]=m;
            sum+=arr[k];
        }
        System.out.println(sum);
        //1/2+1/3+...
        float[] hrr;
        hrr=new float[100];
        float fsum=0;
        float s=2;
        for(int k=0;k<10;k++){
            hrr[k]=1/s;
            s++;
        }
        for(int k=0;k<10;k++){
            fsum+=hrr[k];
        }
        System.out.println(fsum);
        //莲花数
        arr=new int[3];
        for(int k=999;k>99;k--){
            sum=0;
            h=0;
            int temp=k;
            while(temp>0){
                digital=temp%10;
                temp=temp/10;
                arr[h]=digital;
                h++;
                if(h==3){
                    break;
                }
            }
            for(int p=0;p<3;p++){
                sum+=Math.pow(arr[p],3);
            }
            if(sum==k){
                System.out.println(sum);
            }
        }
        //卖西瓜
        int count=0,wl=1020;
        while(wl!=0){
            wl-=2+wl/2;
            count++;
        }
        System.out.println(count+"天");
        //因子之和
        i=sc.nextInt();
        sum=0;
       for(int yin=1;yin<i;yin++){
           if(i%yin==0){
               sum+=yin;
           }
       }
        System.out.println(sum);
       sc.close();
    }
}
