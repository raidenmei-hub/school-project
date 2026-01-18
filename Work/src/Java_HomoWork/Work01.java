package Java_HomoWork;

import java.util.Scanner;
public class Work01 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        //成绩分级
        System.out.println("请输入学生成绩：");
        int score = sc.nextInt();
        String s = sc.next();
        while(true){
            if(score>=0&&score<=100){
               break;
            }
            else {
                System.out.println("错误成绩，请重新输入");
                score=sc.nextInt();
            }
        }
        if(score<60){
            System.out.println("成绩不及格");
        }
        if(score>=60&&score<70){
            System.out.println("成绩及格");
        }
        if(score>=70&&score<80){
            System.out.println("成绩良好");
        }
        if(score>=80){
            System.out.println("成绩优秀");
        }
        //时间判断
        System.out.println("请输入一个0到23的数字：");
        int t = sc.nextInt();
        while(true){
            if(t>=0&&t<=23){
                break;
            }
            else {
                System.out.println("数字不符合要求，请重新输入：");

                t=sc.nextInt();
            }
        }
        if(t<=5){
            System.out.println("该时间为早晨");
        }
        else if(t<=11){
            System.out.println("该时间为上午");
        }
        else if (t <= 17) {
            System.out.println("该时间为下午");
        }
        else {
            System.out.println("该时间为晚上");
        }
        //倍数关系
        int i=sc.nextInt();
        int j=sc.nextInt();
        if(i%j!=0&&j%i!=0){
            System.out.println("真");
        }
        else{
            System.out.println("假");
        }
        //是否整除三
        int x=sc.nextInt();
        if(x%3==0){
            System.out.println("真");
        }
        else{
            System.out.println("假");
        }
        //判断奇偶
        int y=sc.nextInt();
        if(y%2==0){
            System.out.println("该数为偶数");
        }
        else{
            System.out.println("该数为奇数");
        }
        sc.close();
        System.out.println("作业完成");
        sc.close();
    }
}
