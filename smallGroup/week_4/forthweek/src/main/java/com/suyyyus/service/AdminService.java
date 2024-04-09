package com.suyyyus.service;

import com.suyyyus.pojo.Admin;

import java.util.List;

/**
 * 调用Dao层方法
 */
public interface AdminService {
    //进行管理员操作

    //检查管理员信息
    public boolean checkAdmin(String adminname,String password) throws Exception;

    //查询所有管理员
    public List<Admin> queryAll() throws Exception;
}
