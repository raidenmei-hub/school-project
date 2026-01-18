package Java_HomoWork;
import java.util.ArrayList;
public class Work05 {
    public static void main(String[] args){
        ArrayList<String>position=new ArrayList<>();
        position.add("先锋 尖兵");
        position.add("先锋 执旗手");
        position.add("近卫 术战者");
        position.add("近卫 解放者");
        position.add("重装");
        position.add("狙击 速狙");
        position.add("狙击 炮手");
        position.add("术士");
        position.add("辅助");
        position.add("特种");
        position.add(2,"近卫 剑豪");
        position.remove(6);
        System.out.println(position);
    }
}
