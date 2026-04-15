

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        treeNode[] tree = new treeNode[n];

        for (int i = 0; i < n; i++) {
            String nodeValue = scanner.next();
            String leftValue = scanner.next();
            String rightValue = scanner.next();

            int nodeIndex = nodeValue.charAt(0) - 'A';
            int leftIndex = (leftValue.equals(".") ? -1 : leftValue.charAt(0) - 'A');
            int rightIndex = (rightValue.equals(".") ? -1 : rightValue.charAt(0) - 'A');

            tree[nodeIndex] = new treeNode(nodeValue, leftIndex, rightIndex);
        }

        preorder(tree, 0);
        System.out.println();
        inorder(tree, 0);
        System.out.println();
        postorder(tree, 0);
    }

    private static void preorder(treeNode[] tree, int index) {
        if (index == -1)
            return;

        System.out.print(tree[index].value);
        preorder(tree, tree[index].left);
        preorder(tree, tree[index].right);
    }

    private static void inorder(treeNode[] tree, int index) {
        if (index == -1)
            return;

        inorder(tree, tree[index].left);
        System.out.print(tree[index].value);
        inorder(tree, tree[index].right);
    }

    private static void postorder(treeNode[] tree, int index) {
        if (index == -1)
            return;

        postorder(tree, tree[index].left);
        postorder(tree, tree[index].right);
        System.out.print(tree[index].value);
    }
}

class treeNode {
    String value;
    int left;
    int right;

    public treeNode(String value, int left, int right) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}
