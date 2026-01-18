package Java_HomoWork;

public class Work03 {
    public static void main(String[] args){
        /*for(int i=0;i<6;i++) {
            for(int j=0;j<i+1;j++){
                System.out.print("*");
            }
            System.out.print("\n");
        }*/
        for(int i=1;i<=9;i++){
            for(int j=1;j<=i;j++){
                System.out.print(i+"*"+j+"="+i*j+" ");
            }
            System.out.print("\n");
        }
    }
}
