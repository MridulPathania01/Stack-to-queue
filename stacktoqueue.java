import java.util.Stack;
public class stacktoqueue {
    Stack<Integer> s=new Stack<>();
    Stack<Integer> k=new Stack<>();
    // public stacktoqueue(){

    // }
    private int f;
    public void push(int x){
        if(s.isEmpty()){
            f=x;
        }
        s.push(x);
    }
    public int pop(){
        while(!s.isEmpty()){
            k.push(s.pop());
        }
        int ans = k.pop();
        while(!k.isEmpty()){
            s.push(k.pop());
        }
        return ans;
    }
    public boolean empty(){
        return s.isEmpty();
    }
    public int peek(){
        while(!s.isEmpty()){
            k.push(s.pop());
        }
        int ans = k.peek();
        while(!k.isEmpty()){
            s.push(k.pop());
        }
        return ans;
    }
    public static void main(String[] args){
        stacktoqueue q = new stacktoqueue();
        q.push(1);
        q.push(2);
        q.push(3);
        System.out.println(q.pop());
        System.out.println(q.peek());
        System.out.println(q.empty());
    }
}