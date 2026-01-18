package Project;

public class Score_Set {
    private String Term;
    int score;
    public Score_Set(String term,int score){
        this.Term=term;
        this.score=score;
    }
    public void setTerm(String Term){
        this.Term=Term;
    }

    public String getTerm() {
        return Term;
    }

    public void setScore(int score) {
        this.score = score;
    }

    public int getScore() {
        return score;
    }
    public boolean Equals(Score_Set sco){
        boolean modifying;
        if(sco.getTerm().equals(Term)){
            modifying=true;
        }
        else{
            modifying=false;
        }
        return modifying;
    }

}
