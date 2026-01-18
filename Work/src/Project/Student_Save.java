package Project;

import java.util.ArrayList;
import java.util.List;


public class Student_Save {
    private String student_name;
    private String student_number;
    private String student_sex;
    private Score_Set score;
    List<Score_Set> Score_List=new ArrayList<>();
    public Student_Save(String name,String number){
        this.student_name=name;
        this.student_number=number;
    }

    public void setStudent_name(String student_name) {
        this.student_name = student_name;
    }

    public void setStudent_number(String student_number) {
        this.student_number = student_number;
    }

    public String  getName(){
        return student_name;
    }
    public String getStudent_number(){
        return student_number;
    }

    public void setStudent_sex(String student_sex) {
        this.student_sex = student_sex;
    }

    public String getStudent_sex() {
        return student_sex;
    }

    public void setScore(Score_Set score){
        if(Score_List.isEmpty()){
            this.Score_List.add(score);
        }
        else{
            for(Score_Set sco:Score_List){
                int index_score=Score_List.indexOf(sco);
                if(sco.Equals(score)){
                    Score_List.remove(sco);
                    Score_List.add(index_score,score);
                }
                else{
                    Score_List.add(score);
                }
            }
        }
    }

    public void getScore() {
        for(Score_Set score_value:Score_List){
            System.out.println(score_value.getTerm()+" "+score_value.getScore());
        }
    }
    public int scoreSum(){
        int sum=0;
        for(Score_Set sco:Score_List){
            sum+=sco.getScore();
        }
        return sum;
    }
}
