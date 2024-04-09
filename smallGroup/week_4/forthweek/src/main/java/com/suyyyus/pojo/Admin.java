package com.suyyyus.pojo;

/**
 *  管理员类
 */
public class Admin {
    private int id;
    private String adminname;
    private String password;

    public Admin() {
    }

    public Admin(int id, String adminname, String password) {
        this.id = id;
        this.adminname = adminname;
        this.password = password;
    }

    public Admin(String adminname, String password) {
        this.adminname = adminname;
        this.password = password;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getAdminname() {
        return adminname;
    }

    public void setAdminname(String adminname) {
        this.adminname = adminname;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    @Override
    public String toString() {
        return "Admin{" +
                "id=" + id +
                ", adminname='" + adminname + '\'' +
                ", password='" + password + '\'' +
                '}';
    }
}
