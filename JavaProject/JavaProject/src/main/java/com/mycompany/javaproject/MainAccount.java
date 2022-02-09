/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.javaproject;

import java.io.*;
import java.util.*;

/**
 *
 * @author ROOT
 */
public class MainAccount {
    
    static ArrayList<Account> ac = new ArrayList<Account>();
    static File account = new File("account.txt");
    static ObjectOutputStream output = null;
    static ObjectInputStream input = null;
    static ListIterator list = null;
    private String user;
    private String pass;
    
    public MainAccount(){
        
    }

    public MainAccount(String user,String pass) throws Exception {
        this.user = user;
        this.pass = pass;
        add(this.user,this.pass);
    }
    
    public static void add(String username,String pass) throws Exception, ClassNotFoundException{
        
            load_file();
            ac.add(new Account(username, pass));
            output = new ObjectOutputStream(new FileOutputStream(account));
            output.writeObject(ac);
            output.close();

    }
    
    public static void load_file() throws Exception, ClassNotFoundException{
        if(account.isFile()){
               input = new ObjectInputStream(new FileInputStream(account));
               ac = (ArrayList<Account>)input.readObject();
               input.close();
               
        }
    }
    
    public static boolean search(String username,String pass) throws Exception{
        if(account.isFile()){
            
            input = new ObjectInputStream(new FileInputStream(account));
            ac = (ArrayList<Account>) input.readObject();
            input.close();
            list = ac.listIterator();
            
            boolean found = false;
            
            while(list.hasNext()){
                Account temp = (Account)list.next();
                if(temp.username.equals(username) && temp.pass.equals(pass)){
                    found = true;
                }
                
            }
            if(found){
                return true;
            }
        }
        return false;
    }
    
}
