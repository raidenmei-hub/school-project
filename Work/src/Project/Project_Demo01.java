package Project;
import java.util.*;
import java.util.Scanner;

public class Project_Demo01 {
    //学生保存
    static List<Student_Save>student=new ArrayList<>();
    //用户保存
    static Map<String,String> admin=new HashMap<>();
    static boolean modifying=true;


    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        boolean systemRunning=true;
        while(systemRunning) {
            System.out.println("~~~~~~~~~~欢迎使用学生信息管理系统~~~~~~~~~~");
            System.out.println("请选择操作：1.登录  2.注册  3.退出");
            modifying = true;
            while (modifying) {
                int choice = sc.nextInt();
                switch (choice) {
                    case 1:
                        modifying = false;
                        if (admin.isEmpty()) {
                            System.out.println("没有用户，请先注册");
                            Admin_set(sc);
                        } else {
                            Login(sc);
                        }
                        break;
                    case 2:
                        modifying = false;
                        Admin_set(sc);
                        break;
                    case 3:
                        systemRunning=false;
                        exit();
                    default:
                        System.out.println("错误操作，请重新输入");
                        break;
                }
            }
        }
        sc.close();
    }
    //退出系统
    public static void exit(){
        System.out.println("程序退出中...\n欢迎您再次使用");
        System.exit(0);
    }
    //登录
    public static void Login(Scanner sc){
        boolean login=false;
        while(true) {
            System.out.println("请输入用户名：");
            String username = sc.next();
            System.out.println("请输入密码：");
            String password = sc.next();
            if (admin.containsKey(username) && password.equals(admin.get(username))) {
                System.out.println("登录成功！" + username + "欢迎您！");
                try {
                    Thread.sleep(500);  // 暂停0.5秒
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                login=true;
                break;
            } else {
                System.out.println("用户名或密码错误，请重新输入");
            }
        }
        if(login){
            clearConsole();
            try {
                Thread.sleep(500);  // 暂停0.5秒
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            Student_System(sc);
        }
    }
    //注册
    public static void Admin_set(Scanner sc){
        modifying=true;
        while(modifying) {
            System.out.println("请输入用户名：");
            String admin_name = sc.next();
            String admin_password_temp;
            String admin_password;
            while (true) {
                System.out.println("请输入密码：");
                admin_password_temp = sc.next();
                System.out.println("请确认密码：");
                admin_password = sc.next();
                if (admin_password.equals(admin_password_temp)) {
                    break;
                } else {
                    System.out.println("两次密码不相同，请重新输入：");
                }
            }
            if (admin.containsKey(admin_name)) {
                System.out.println("用户名重复，请重新输入");
            } else {
                admin.put(admin_name, admin_password);
                System.out.println("注册成功！");
                modifying=false;
                clearConsole();
                try {
                    Thread.sleep(500);  // 暂停0.5秒
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                Student_System(sc);
            }
        }
    }
    //系统操作
    public static void Student_System(Scanner sc){
        clearConsole();
        System.out.println("请选择操作：1.学生信息录入  2.学生信息查询  4.学生信息删除  3.退出");
        modifying=true;
        while(modifying) {
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    modifying=false;
                    setStudent(sc);
                    break;
                case 2:
                    if(student.isEmpty()){
                        System.out.println("没有学生，请添加学生");
                        NewStudentSet(sc);
                    }
                    else{
                        Student_Check(sc);
                    }
                    break;
                case 3:
                    clearConsole();
                    modifying=false;
                    return;
                default:
                    System.out.println("无效操作，请重新输入");
                    break;
            }
        }
    }
    //学生信息显示方法
    public static void Student_Print(Student_Save student_select){
        System.out.print("当前学生信息："+
                "\n姓名："+student_select.getName()+
                "\n性别："+student_select.getStudent_sex()+
                "\n学号："+student_select.getStudent_number()+
                "\n成绩：");
        System.out.print("   ");
        student_select.getScore();
        System.out.print("   ");
        System.out.println("总分："+student_select.scoreSum());
    }
    //学生信息查询
    public static void  Student_Check(Scanner sc){
        System.out.println("请选择操作；1.查询单个学生  2.浏览所有学生  3.退出");
        modifying=true;
        while (modifying){
            int choice=sc.nextInt();
            switch (choice){
                case 1:
                    System.out.println("请输入要查询的学生姓名或学号：");
                    String student_find=sc.next();
                    List<Student_Save>foundStudent= FindStudent(student_find);
                    if(foundStudent.isEmpty()){
                        System.out.println("未找到该学生");
                        Student_System(sc);
                        return;
                    }
                    else if(foundStudent.size()>1){
                        for(Student_Save stu:foundStudent){
                            System.out.println(stu.getName()+stu.getStudent_number());
                        }
                        System.out.println("找到多个符合对象，请输入学号选择");
                        modifying=true;
                        while (modifying) {
                            String number_select = sc.next();
                            Student_Save student_select = null;
                            for (Student_Save stu : foundStudent) {
                                if (stu.getStudent_number().equals(number_select)) {
                                    student_select = stu;
                                }
                            }
                            if (student_select != null) {
                                modifying=false;
                                //学生信息显示方法
                                Student_Print(student_select);
                                break;
                            } else {
                                System.out.println("输入错误，请重试");
                            }
                        }
                    }
                    else{
                        //学生信息显示方法
                        Student_Print(foundStudent.get(0));
                        break;
                    }
                case 2:
                    for(Student_Save stu:student){
                        System.out.println(stu.getName()+" "+stu.getStudent_number());
                    }
                    break;
                case 3:
                    modifying=false;
                    Student_System(sc);
                    return;
                default:
                    System.out.println("错误操作，请重新输入");
                    break;
            }
        }
    }
    //学生信息录入
    public static void setStudent(Scanner sc){
        System.out.println("请选择操作：1.添加学生  2.修改学生信息  3.退出");
        modifying=true;
        while(modifying) {
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    modifying=false;
                    NewStudentSet(sc);
                    return;
                case 2:
                    modifying=false;
                    if(student.isEmpty()){
                        System.out.println("没有学生，请添加学生");
                        NewStudentSet(sc);
                    }
                    else {
                        StudentSet(sc);
                    }
                    return;
                case 3:
                    Student_System(sc);
                    return;
                default:
                    System.out.println("无效操作，请重新输入");
                    break;
            }
        }
    }
    //添加学生
    public static void NewStudentSet(Scanner sc){
        System.out.println("请输入学生基本信息：姓名 学号 性别");
        String name= sc.next();
        String number= sc.next();
        String sex= sc.next();
        System.out.println("新添加学生：\n姓名："+name+"\n学号："+number+"\n性别："+sex+"\n1.确认  2.修改");
        int choice=sc.nextInt();
        modifying=true;
        while(modifying) {
            switch (choice) {
                case 1:
                    modifying=false;
                    Student_Save Student = new Student_Save(name, number);
                    student.add(Student);
                    setStudent(sc);
                    return;
                case 2:
                    modifying=false;
                    NewStudentSet(sc);
                    return;
                default:
                    modifying=false;
                    System.out.println("无效操作，请重新输入");
                    break;
            }
        }
    }
    //删除学生
    public static void StudentDelete(Scanner sc){
        System.out.println("请输入学号或姓名删除学生");
        String Find=sc.next();
        List<Student_Save>foundStudents=FindStudent(Find);
        if(foundStudents.isEmpty()){
            System.out.println("未找到该学生");
            setStudent(sc);
        }
        else{
            if(foundStudents.size()>1){
                for(Student_Save stu:foundStudents){
                    System.out.println("姓名："+stu.getName()+"学号"+stu.getStudent_number());
                }
                System.out.println("查找到多个符合对象，请输入学号选择");
                String choice_number=sc.next();
                Student_Save student_select=null;
                modifying=true;
                while(modifying) {
                    for (Student_Save stu : foundStudents) {
                        if (stu.getStudent_number().equals(choice_number)) {
                            student_select = stu;
                            break;
                        }
                    }
                    if (student_select != null) {
                        student.remove(student_select);
                        modifying=false;
                    } else {
                        System.out.println("错误学号，请重新输入");
                    }
                }
            }
            else{
                student.remove(foundStudents.get(0));
            }

        }
    }
    //查找学生方法
    public static List<Student_Save>FindStudent(String Find){
        List<Student_Save>result=new ArrayList<>();
        for(Student_Save stu:student){
            if(stu.getName().equals(Find)){
                result.add(stu);
            }
            else if(stu.getStudent_number().equals(Find)){
                result.add(stu);
            }
        }
        return result;
    }

    //学生信息修改方法
    public static void Student_Set(Student_Save stu,Scanner sc,int index_student){
        System.out.print("当前学生信息："+
                            "\n姓名："+stu.getName()+
                            "\n性别："+stu.getStudent_sex()+
                            "\n学号："+stu.getStudent_number()+
                            "\n成绩：");
        System.out.print("   ");
        stu.getScore();
        modifying=true;
        while(modifying) {
            System.out.println("请选择操作：1.修改姓名  2.修改性别  3.修改学号  4.修改成绩  5.全部修改  6.保存修改  7.取消");
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.println("请输入新姓名：");
                    String new_name = sc.next();
                    stu.setStudent_name(new_name);
                    System.out.println("修改成功");
                    break;
                case 2:
                    System.out.println("请输入新性别：");
                    String new_sex = sc.next();
                    stu.setStudent_sex(new_sex);
                    System.out.println("修改成功");
                    break;
                case 3:
                    System.out.println("请输入新学号：");
                    String new_number = sc.next();
                    for(Student_Save student_current : student){
                        if(student_current!=stu&&student_current.getStudent_number().equals(new_number)){
                            System.out.println("学号已存在");
                        }
                        else{
                            stu.setStudent_number(new_number);
                            System.out.println("修改成功");
                        }
                    }
                    break;
                case 4:
                    System.out.println("请输入新成绩：");
                    String new_term=sc.next();
                    int new_score = sc.nextInt();
                    Score_Set nScore=new Score_Set(new_term,new_score);
                    stu.setScore(nScore);
                    System.out.println("修改成功");
                    break;
                case 5:
                    System.out.println("请输入学生姓名，性别，学号，成绩：");
                    new_name = sc.next();
                    new_sex = sc.next();
                    new_number = sc.next();
                    new_term=sc.next();
                    new_score = sc.nextInt();
                    Score_Set nScore1=new Score_Set(new_term,new_score);
                    for(Student_Save student_current : student){
                        if(student_current!=stu&&student_current.getStudent_number().equals(new_number)){
                            System.out.println("学号已存在");
                        }
                        else{
                            stu.setStudent_name(new_name);
                            stu.setStudent_number(new_number);
                            stu.setStudent_sex(new_sex);
                            stu.setScore(nScore1);
                            System.out.println("修改成功");
                        }
                    }
                    break;
                case 6:
                    modifying=false;
                    System.out.println("当前学生信息："+
                                        "\n姓名："+stu.getName()+
                                        "\n性别："+stu.getStudent_sex()+
                                        "\n学号："+stu.getStudent_number()+
                                        "\n成绩：");
                    System.out.print("   ");
                    stu.getScore();
                    if(index_student>=0&&index_student<student.size()){
                        student.remove(index_student);
                        student.add(index_student,stu);
                    }
                    else{
                        student.add(stu);
                    }
                    System.out.println("修改保存成功！");
                    setStudent(sc);
                    return;
                case 7:
                    modifying=false;
                    Student_System(sc);
                    return;
                default:
                    System.out.println("错误操作，请重新输入");
                    break;
            }
        }
    }
    //修改学生信息
    public static void StudentSet(Scanner sc) {
        System.out.println("请输入要修改的学生姓名或学号");
        String Find=sc.next();
        List<Student_Save>foundStudents=FindStudent(Find);
        if(foundStudents.isEmpty()){
            System.out.println("未找到该学生");
            setStudent(sc);
        }
        else{
            if(foundStudents.size()>1){
                for(Student_Save stu :foundStudents){

                    System.out.println("姓名："+stu.getName()+"学号"+stu.getStudent_number());
                }
                System.out.println("查询到多个符合对象，请输入学号进行选择：");
                String choice_number=sc.next();
                Student_Save student_select=null;
                modifying=true;
                while(modifying) {
                    for (Student_Save stu : foundStudents) {
                        if (stu.getStudent_number().equals(choice_number)) {
                            student_select = stu;
                            break;
                        }
                    }
                    if (student_select != null) {
                        int index_student=student.indexOf(student_select);
                        Student_Set(student_select,sc,index_student);
                        modifying=false;
                    } else {
                        System.out.println("错误学号，请重新输入");
                    }
                }
            }
            else{
                int index_student=student.indexOf(foundStudents.get(0));
                Student_Set(foundStudents.get(0),sc,index_student);
            }
        }
    }
    //清空控制台
    private static void clearConsole() {
        for (int i = 0; i < 100; i++) {
            System.out.println();
        }
           /* try {
                // 方法1：使用Runtime执行命令
                Runtime.getRuntime().exec("cmd /c cls");

                // 方法2：输出特殊控制字符
                System.out.print("\f");  // 换页符，在某些控制台有效
                System.out.flush();

            } catch (Exception e) {
                // 备用：空行覆盖
                for (int i = 0; i < 30; i++) {
                    System.out.println();
                }
            }*/
            /*// Windows系统
            if (System.getProperty("os.name").contains("Windows")) {
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            }
            // Linux/Mac系统
            else {
                System.out.print("\033[H\033[2J");
                System.out.flush();
            }*/
    }
}
