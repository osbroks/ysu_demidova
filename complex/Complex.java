/**
 * Created by hamas on 30.04.17.
 */

public class Complex {
    private int im, re;
    private final String complexString;
    private String[] complexReIm;

    Complex(){
        this(null);
    }

    Complex(final String complexString){
        this.complexString = complexString;
        getString(this.complexString);
        this.re = Integer.parseInt(complexReIm[0]);
        this.im = Integer.parseInt(complexReIm[1]);
    }

    private void getString(final String complexString) {
        complexReIm = complexString.split(" ");
    }

    public Complex summComplex(Complex complex) {
        Complex newComplex = new Complex();
        newComplex.re = this.re + complex.re;
        newComplex.im = this.im + complex.im;
        return newComplex;
    }

}
