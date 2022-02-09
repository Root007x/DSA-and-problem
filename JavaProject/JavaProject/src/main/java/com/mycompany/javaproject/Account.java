/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.javaproject;

import java.io.*;

public class Account implements Serializable{
    public String username;
    public String pass;

    public Account(String username,String pass) {
        this.username = username;
        this.pass = pass;
    }
}
