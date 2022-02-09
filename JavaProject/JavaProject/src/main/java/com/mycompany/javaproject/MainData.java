/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.javaproject;

import static com.mycompany.javaproject.MainAccount.ac;
import static com.mycompany.javaproject.MainAccount.account;
import static com.mycompany.javaproject.MainAccount.input;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.ListIterator;
import javax.swing.JOptionPane;

/**
 *
 * @author ROOT
 */
public class MainData {
    
    static ArrayList<Data> arr_list = new ArrayList<Data>();
    static File veccine = new File("veccinelist.txt");
    static ObjectOutputStream output = null;
    static ObjectInputStream input = null;
    static ListIterator list = null;
    
    String first_name;
    String last_name;
    String age;
    String gender;
    String national_id;
    String phone_number;
    String day;
    String month;
    String year;
    String address;
    String email;

    public MainData() {
    }

    public MainData(String first_name, String last_name, String age, String gender, String national_id, String phone_number, String day, String month, String year, String email, String address) throws Exception{
        this.first_name = first_name;
        this.last_name = last_name;
        this.age = age;
        this.gender = gender;
        this.national_id = national_id;
        this.phone_number = phone_number;
        this.day = day;
        this.month = month;
        this.year = year;
        this.address = address;
        this.email = email;
        add_member(this.first_name, this.last_name, this.age, this.gender, this.national_id, this.phone_number, this.day, this.month, this.year, this.email, this.address);
        update(this.first_name, this.last_name, this.age, this.gender, this.national_id, this.phone_number, this.day, this.month, this.year, this.email, this.address);
    }
    public MainData(String national_id) throws Exception{
        this.national_id = national_id;
        delete(national_id);
    }
    
    public static void add_member(String first_name, String last_name, String age, String gender, String national_id, String phone_number, String day, String month, String year, String email, String address) throws Exception, ClassNotFoundException{
        load_file();
        arr_list.add(new Data(first_name, last_name, age, gender, national_id, phone_number, day, month, year, email, address));
        output = new ObjectOutputStream(new FileOutputStream(veccine));
        output.writeObject(arr_list);
        output.close();
        
    }
    
    public static void load_file() throws Exception, ClassNotFoundException{
        if(veccine.isFile()){
               input = new ObjectInputStream(new FileInputStream(veccine));
               arr_list = (ArrayList<Data>)input.readObject();
               input.close();
               
        }
    }
    
       public static boolean search(String national_id) throws Exception{
        if(veccine.isFile()){
            
            input = new ObjectInputStream(new FileInputStream(veccine));
            arr_list = (ArrayList<Data>) input.readObject();
            input.close();
            list = arr_list.listIterator();
            
            boolean found = false;
            
            while(list.hasNext()){
                Data temp = (Data)list.next();
                if(temp.national_id.equals(national_id)){
                    found = true;
                }
                
            }
            if(found){
                return true;
            }
        }
        return false;
    }
        public static Data search_card(String national_id) throws Exception{
            if(veccine.isFile()){
            input = new ObjectInputStream(new FileInputStream(veccine));
            arr_list = (ArrayList<Data>) input.readObject();
            input.close();
            list = arr_list.listIterator();
                        
            while(list.hasNext()){
                Data temp = (Data)list.next();
                if(temp.national_id.equals(national_id)){
                    return temp;
                }
                
            }
          
        }
        return null;
    }
        public static void update(String first_name, String last_name, String age, String gender, String national_id, String phone_number, String day, String month, String year, String email, String address) throws Exception{
            
            if(veccine.isFile()){
            input = new ObjectInputStream(new FileInputStream(veccine));
            arr_list = (ArrayList<Data>) input.readObject();
            input.close();
            list = arr_list.listIterator();
            boolean found = false;
                        
            while(list.hasNext()){
                Data temp = (Data)list.next();
                if(temp.national_id.equals(national_id)){
                    list.set(new Data(first_name, last_name, age, gender, national_id, phone_number, day, month, year, email, address));
                    found = true;
                }
                
            }
            if(found){
                output = new ObjectOutputStream(new FileOutputStream(veccine));
                output.writeObject(arr_list);
                output.close();
            }
            else{
                
            }
          
        }
        else{
                JOptionPane.showMessageDialog(null, "File not found!!");
        }
    }
        public static void delete(String national_id) throws  Exception{
            
            if(veccine.isFile()){
            input = new ObjectInputStream(new FileInputStream(veccine));
            arr_list = (ArrayList<Data>) input.readObject();
            input.close();
            list = arr_list.listIterator();
            boolean found = false;
                        
            while(list.hasNext()){
                Data temp = (Data)list.next();
                if(temp.national_id.equals(national_id)){
                    list.remove();
                    found = true;
                }
                
            }
            if(found){
                output = new ObjectOutputStream(new FileOutputStream(veccine));
                output.writeObject(arr_list);
                output.close();
            }
            else{
                
            }
          
        }
        else{
                JOptionPane.showMessageDialog(null, "File not found!!");
        }
        }
}
