package Java_HomoWork;
import java.util.Scanner;
public class Work_Student_Main {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        Work_student student=new Work_student();
        student.name=sc.next();
        System.out.println("姓名："+student.name);
        printName(student);
    }
    public static void printName(Work_student student){
        System.out.println(student.name);
    }
}
