public class selfNumber{

    public static void main(String[] args){
        boolean[] check = new boolean[10001];

        for(int i=1; i<=10000; i++){
            int n = d(i)+i;
            if(n<=10000)
                check[n] = true;
        }
        for(int i=1; i<=10000; i++) {
            if (!check[i])
                System.out.println(i);
        }
    }
    public static int d(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
}