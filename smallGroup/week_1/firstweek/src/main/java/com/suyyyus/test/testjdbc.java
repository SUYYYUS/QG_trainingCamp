package com.suyyyus.test;

import com.suyyyus.Dao.UserDaoImpl;
import com.suyyyus.pojo.User;
import com.suyyyus.utils.CRUDUtils;
import com.suyyyus.utils.JDBCUtils;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class testjdbc {
    public static void main(String[] args) throws Exception {
        //扫描器，方便使用
        Scanner sc = new Scanner(System.in);
        int i;//选择功能所用变量
        User user = new User();//初始化对象
        int id = 0; // 查询用户所用变量
        //创建一个CRUDUtils类对象
        CRUDUtils crudUtils = new CRUDUtils();
        //创建一个导层来实现各功能
        UserDaoImpl userDao = new UserDaoImpl();

        while (true) {
            System.out.println("请选择想要进行的操作：");
            welcome();
            i = sc.nextInt();
            switch (i){
                case 1: //显示所有用户信息
                    userDao.queryAll();
                    System.out.println("操作完成");
                    break;
                case 2: //添加新的用户信息
                    System.out.println("请依次输入姓名，密码，性别，住址");
                    user = new User( sc.next(),sc.next(), sc.next(), sc.next());
                    userDao.insertUser(user);
                    System.out.println("添加成功");
                    break;
                case 3: // 更改用户信息
                    userDao.queryAll();//先提供所有用户信息
                    System.out.println("版本稍稍落后");
                    System.out.println("请选择您要更改的用户的内容，依次为姓名，密码，性别，地址（若不改则输入原本数据）：");
                    user = new User( sc.next(),sc.next(), sc.next(), sc.next());
                    userDao.updateinfo(user);
                    System.out.println("更改成功");
                    break;
                case 4: //删除用户信息
                    userDao.queryAll();//先提供所有用户信息
                    System.out.println("请选择您要删除的用户的id：");
                    id = sc.nextInt();
                    userDao.deleteUser(id);
                    System.out.println("删除完成");
                    break;
                case 5: // 查询某个用户信息
                    System.out.println("请选择您要查询的用户的id：");
                    id = sc.nextInt();
                    userDao.queryById(id);
                    break;
                case 0: //退出系统
                    System.out.println("期待下次相见~");
                    return ;
                default://输入错误处理
                    System.out.println("还没有这个功能，再试试其他吧~~");
                    break;
            }
        }
    }

    //菜单页面
    public static void welcome(){
        System.out.println("=========================");
        System.out.println("1.显示所有用户信息");
        System.out.println("2.添加新的用户信息");
        System.out.println("3.更改用户信息");
        System.out.println("4.删除用户信息");
        System.out.println("5.查询某个用户信息");
        System.out.println("0.退粗");
        System.out.println("=========================");
    }
}
