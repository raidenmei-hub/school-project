package Game_Demo;

public class Game_Character {
    protected String name;
    protected String sex;
    protected String ZhongZu;
    protected int physical_attack;
    protected int imagine_attack;
    protected int physical_defence;
    protected int imagine_defence;
    protected int bar;

    public void setName(String name) {
        ;this.name=name;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public void setZhongZu(String zhongZu) {
        this.ZhongZu = zhongZu;
    }
    private String[] Zhongzu=new String[]{"人类","妖怪","堕神"};
}
