package Connections;

import java.util.Collections;
import java.util.Random;

import java.util.*;
public class ShuffleUsingVector {
    public static void main(String args[]){
        Vector<Integer>vec=new Vector<Integer>();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter elements you want to shuffle :");
        boolean flag=true;
        int temp;
        Random rand=new Random();
        while(flag){
            temp=sc.nextInt();
            if(temp==0){
                flag=false;
            }
            else{
                vec.add(temp);
            }
        }
        System.out.println("The elements are :"+vec);

        int length=vec.size();
        for(int i=length-1;i>=0;i--) {
            int x = rand.nextInt(length);
            Collections.swap(vec, x, length - 1);
            System.out.println(vec);
            length--;
        }
        System.out.println("Shuffled elements are "+vec);
    }




}