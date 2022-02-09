/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.javaproject;

import java.util.Calendar;
import java.util.Date;

public class TimeAndDate {
    static Date date = new Date();
    static Calendar c = Calendar.getInstance();

    public TimeAndDate() {
    }
    
    public static String [] getDate1(){
        c.add(Calendar.DATE, 30);
        date = c.getTime();
        String temp = date.toString();
        String [] date = temp.split(" ");
        return date;
    }
    
    public static String[] getDate2(){
        c.add(Calendar.DATE, 60);
        date = c.getTime();
        String temp = date.toString();
        String [] date = temp.split(" ");
        return date;
    }
}
