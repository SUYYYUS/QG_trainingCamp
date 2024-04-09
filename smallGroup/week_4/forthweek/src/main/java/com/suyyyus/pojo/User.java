package com.suyyyus.pojo;

import java.time.LocalDateTime;

/**
 * 用户类
 */
public class User {
   private int id;
   private String cardid;
   private String username;
   private String password;
   private String gender;
   private String address;
   private String create_time;

    public User(int id, String cardid, String username, String password, String gender, String address, String create_time) {
        this.id = id;
        this.cardid = cardid;
        this.username = username;
        this.password = password;
        this.gender = gender;
        this.address = address;
        this.create_time = create_time;
    }

    public User(String cardid, String username, String password, String gender, String address, String create_time) {
        this.cardid = cardid;
        this.username = username;
        this.password = password;
        this.gender = gender;
        this.address = address;
        this.create_time = create_time;
    }

    public User(String username, String password, String gender, String address) {
        this.username = username;
        this.password = password;
        this.gender = gender;
        this.address = address;
    }

    public User(String cardid, String username, String password, String gender, String address) {
        this.cardid = cardid;
        this.username = username;
        this.password = password;
        this.gender = gender;
        this.address = address;
    }

   /* public User(String username, String password, String gender, String address, String create_time) {
        this.username = username;
        this.password = password;
        this.gender = gender;
        this.address = address;
        this.create_time = create_time;
    }*/

    public User() {
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getCardid() {
        return cardid;
    }

    public void setCardid(String cardid) {
        this.cardid = cardid;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getCreate_time() {
        return create_time;
    }

    public void setCreate_time(String create_time) {
        this.create_time = create_time;
    }

    @Override
    public String toString() {
        return "User{" +
                "id=" + id +
                ", cardid='" + cardid + '\'' +
                ", username='" + username + '\'' +
                ", password='" + password + '\'' +
                ", gender='" + gender + '\'' +
                ", address='" + address + '\'' +
                ", create_time=" + create_time +
                '}';
    }
}
