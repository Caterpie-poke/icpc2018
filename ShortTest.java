public class ShortTest {
    public static void main(String[] args){
        Test t = new Test();
        // t.test3();
        String str = "push 67";
        int a = str.split(" ").length;
        String de = "123a";
        System.out.println(Integer.parseInt(de));
        System.out.println(a);
    }
}

class Test {
    public String bin = "<Start>";
    public void test1(){
        String binary = "";
        binary+="Hello,";
        binary+=" world!\n";
        System.out.println(binary);
    }
    public String addH(){
        this.bin += "<Hoge>";
        return "<Hello>";
    }
    public void test2(){
        this.bin += addH();
        System.out.println(this.bin);
    }
    public void test3(){
        String str1 = "PUSH 32";
        String str2 = "ADD";
        System.out.println(str1.split(" ")[0]);
        System.out.println(str2.split(" ")[0]);
    }
}