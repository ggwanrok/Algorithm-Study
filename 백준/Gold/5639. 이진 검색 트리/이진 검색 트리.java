

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Node head = new Node(scanner.nextInt());
        while (scanner.hasNextInt()) {
            head.setNext(scanner.nextInt());
        }
        head.search(head);
    }
}

class Node {
    Node left;
    Node right;

    int value;

    public Node getLeft(){
        return this.left;
    }

    public Node getRight(){
        return this.right;
    }
    public void setNext(int value){
        if(this.value > value){
            if(this.getLeft() == null){
                this.left = new Node(value);
            }
            else{
                this.left.setNext(value);
            }
        }
        if(this.value < value){
            if(this.getRight() == null){
                this.right = new Node(value);
            }
            else{
                this.right.setNext(value);
            }
        }
    }
    public Node(int value){
        this.value = value;
    }

    public void search(Node head){
        if(head.left != null){
            search(head.left);
        }
        if(head.right != null){
            search(head.right);
        }
        System.out.println(head.value);
    }
}