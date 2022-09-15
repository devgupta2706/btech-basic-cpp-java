interface A {
    void abc();

}

interface B extends A {
    void pqr();
}

interface C extends A {
    void mno();

}

class D implements B, C {

    void nope() {
        System.out.println("D");
    }

    public void abc() {
        System.out.println("A");
    }

    public void pqr() {
        System.out.println("B");
    }

    public void mno() {
        System.out.println("C");
    }

}

class Check {
    public static void main(String[] args) {
        D d = new D();
        d.abc();
        d.mno();
        d.nope();
        d.pqr();
    }
}