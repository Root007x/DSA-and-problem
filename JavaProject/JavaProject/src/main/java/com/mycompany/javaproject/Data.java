/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.javaproject;

/**
 *
 * @author ROOT
 */
import java.io.Serializable;

public class Data implements Serializable {

    public String first_name;
    public String last_name;
    public String age;
    public String gender;
    public String national_id;
    public String phone_number;
    public String day;
    public String month;
    public String year;
    public String address;
    public String email;

    public Data(String first_name,String last_name,String age,String gender,String national_id,String phone_number,String day,String month,String year,String email,String address) {
        this.first_name = first_name;
        this.last_name = last_name;
        this.age = age;
        this.gender = gender;
        this.national_id = national_id;
        this.phone_number = phone_number;
        this.day = day;
        this.month = month;
        this.year = year;
        this.email = email;
        this.address = address;
    }
    
}
