import java.util.ArrayList;

enum Note {
    MIDDLE_C,
    C_SHART,
    B_FLAT
}

abstract class Instrument {
    abstract void play(Note n);
    abstract void adjust();
}

class Wind extends Instrument {
    public void play(Note n) {
        System.out.println("wind.play() " + n);
    }

    public void adjust() {
        System.out.println("wind.adjust() ");
    }
}

class Brass extends Wind {
    public void play(Note n) {
        System.out.println("Brass.play() " + n);
    }

    public void adjust() {
        System.out.println("Brass.adjust() ");
    }
}

class WoodWind extends Wind {
    public void play(Note n) {
        System.out.println("WoodWind.play() " + n);
    }
}

public class Music {
    void turn(Instrument i) {
        i.play(Note.MIDDLE_C);
    }
    void adjust(Instrument i) {
        i.adjust();
    }

    void tuneAll(ArrayList<Instrument> e) {
        for(int j = 0; j < e.size(); j++) {
            Instrument i = e.get(j);
            adjust(i);
            turn(i);
        }
    }
    public static void main(String[] args) {
        Music music = new Music();
        ArrayList<Instrument> orchestra = new ArrayList<>();
        orchestra.add(new Wind());
        orchestra.add(new WoodWind());
        music.tuneAll(orchestra);
    }
}