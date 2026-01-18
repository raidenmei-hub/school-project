package Project;
import java.util.Scanner;
public class Project_Demo {
    static int student_count=0;
    static String[][] student_save=new String[100][4];
    public static void exit(){
        System.out.println("系统退出中...");
        System.out.println("感谢使用，再见！");
        System.exit(0);
    }
    public  static void student_finding(Scanner sc){
        System.out.print("请输入要查询的学生姓名或学号：");
        String temp= sc.next();
        boolean found=false;
        for(int i=0;i<student_count;i++){
                if(temp.equals(student_save[i][0])||temp.equals(student_save[i][1])) {
                    System.out.print("姓名：" + student_save[i][0] + "\n学号：" + student_save[i][1] + "\n专业：" + student_save[i][2] + "\n班级：" + student_save[i][3]);
                    found = true;
                }
        }
        if(!found){
            System.out.println("未找到该学生");
        }
    }
    public static void student_input(Scanner sc){
        System.out.print("请输入学生姓名：");
        String student_name= sc.next();
        System.out.print("请输入学生学号：");
        String student_number= sc.next();
        System.out.print("请输入学生专业：");
        String student_subject= sc.next();
        System.out.print("请输入学生班级：");
        String student_class= sc.next();
        System.out.print("新学生：\n姓名："+student_name+"\n学号："+student_number+"\n专业："+student_subject+"\n班级："+student_class+"\n(1)确认 (2)修改");
        int choice= sc.nextInt();
        if(choice==1){
            if(student_count>99){
                System.out.println("已到达最大学生量");
                student_system(sc);
                return;
            }
            student_save[student_count] = new String[]{student_name, student_number, student_subject, student_class};
            student_count++;
            System.out.print("新学生已保存\n是否继续录入\n1.是  2.否");
            choice= sc.nextInt();
            while (true) {
                if (choice >= 1 && choice <= 2) {
                    break;
                } else {
                    System.out.println("错误操作，请重新输入");
                    choice = sc.nextInt();
                }
            }
            if(choice==1){
                    student_input(sc);
            }
            else if(choice==2){
                student_system(sc);
                return;
            }
        }
        if(choice==2){
            boolean modifying = true;
            while(modifying) {
                System.out.print("请选择您需要修改的内容：\n1.学生姓名 2.学生学号 3.学生专业 4.学生班级 5.保存并退出 6.取消");
                choice = sc.nextInt();
                switch (choice) {
                    case 1:
                        System.out.print("请输入学生姓名：");
                        student_name = sc.next();
                        break;
                    case 2:
                        System.out.print("请输入学生学号：");
                        student_number = sc.next();
                        break;
                    case 3:
                        System.out.print("请输入学生专业：");
                        student_subject = sc.next();
                        break;
                    case 4:
                        System.out.print("请输入学生班级：");
                        student_class = sc.next();
                        break;
                    case 5:
                        if(student_count>=100){
                            System.out.println("已达到最大学生量");
                        }
                        else{
                            student_save[student_count] = new String[]{student_name, student_number, student_subject, student_class};
                            student_count++;
                            System.out.println("学生信息已保存");
                        }
                        modifying = false;
                        student_system(sc);
                        return;// 立即结束整个student_input方法
                    // 后面的代码都不会执行！
                    case 6:
                        System.out.println("已取消录入");
                        student_system(sc);
                        return;
                    default:
                        System.out.println("无效选择，请重新输入");
                        break;
                }
                System.out.print("新学生：\n姓名："+student_name+"\n学号："+student_number+"\n专业："+student_subject+"班级："+student_class);
            }
            if(choice==5){
                student_system(sc);
            }
        }
    }
    public static void student_system(Scanner sc){
        System.out.print("请选择您要进行的操作：\n    1.学生信息录入\n    2.学生信息查询\n    3.退出系统\n");
        int choice= sc.nextInt();
        while (true) {
            if (choice >= 1 && choice <= 3) {
                break;
            } else {
                System.out.println("错误操作，请重新输入");
                choice = sc.nextInt();
            }
        }
        switch (choice){
            case 1:
                student_input(sc);
                break;
            case 2:
                student_finding(sc);
                break;
            case 3:
                exit();
            default:
                break;
        }
    }
    public static void main(String[] args) {
        System.out.println("----------欢迎使用学生信息管理系统-----------");
        System.out.print("请选择您要进行的操作：\n    1.登录\n    2.用户注册\n    3.退出系统\n");
        Scanner sc = new Scanner(System.in);
        int choice = sc.nextInt();
        while (true) {
            if (choice >= 1 && choice <= 3) {
                break;
            } else {
                System.out.println("错误操作，请重新输入");
                choice = sc.nextInt();
            }
        }
        int admin_count=0;
        String[][] admin_save=new String[100][];
       if(choice==2) {
           System.out.print("请输入用户名：");
           String user = sc.next();
           boolean username_exist = false, username_scan = true;
           while (username_scan) {
               for (int i = 0; i < admin_count; i++) {
                   if (admin_save[i] != null && admin_save.length >= 1) {
                       if (user.equals(admin_save[i][0])) {
                           username_exist = true;
                           break;
                       }
                   }
               }
               if (username_exist) {
                   System.out.print("用户名已存在，请重新输入：");
                   user= sc.next();
               } else {
                   username_scan = false;
               }
           }
           boolean pass_scan=true;
           System.out.print("请输入密码：");
           String pass_temp = sc.next();
           System.out.print("请确认密码：");
           String pass_confirm = sc.next();
           while(pass_scan) {
               if(admin_count>99){
                   System.out.println("已到达最大用户量");
                   break;
               }
               else if (pass_temp.equals(pass_confirm)) {
                   System.out.println("注册成功！");
                   admin_save[admin_count]=new String[]{user,pass_temp};
                   admin_count++;
                   pass_scan = false;
               }
               else{
                   System.out.print("两次密码输入不相同，请重新输入：");
                   pass_confirm=sc.next();
               }
           }
           student_system(sc);
       }
        else if (choice == 1) {
            System.out.print("请输入用户名：");
            String username_temp = sc.next();
            System.out.print("请输入密码：");
            String password_temp=sc.next();
            boolean scan=true,loginSucces=false;
            while(scan){
                for(int i=0;i<admin_count;i++){
                    if(admin_save[i][0].equals(username_temp)&&admin_save[i][1].equals(password_temp)){
                        System.out.println("登陆成功！");
                        scan=false;
                        loginSucces=true;
                    }
                }
                if(!loginSucces){
                    System.out.println("用户名或密码错误，请重新输入");
                    System.out.print("请输入用户名：");
                    username_temp = sc.next();
                    System.out.print("请输入密码：");
                    password_temp=sc.next();
                }
            }
            student_system(sc);
        }
        else if(choice==3){
            exit();
        }
        sc.close();
    }
}
