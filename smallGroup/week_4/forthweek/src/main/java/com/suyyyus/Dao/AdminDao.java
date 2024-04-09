package com.suyyyus.Dao;

import com.suyyyus.pojo.Admin;

import java.util.List;

public interface AdminDao {
    //进行登录
    public boolean checkAdmin(String adminname, String password) throws Exception;

    //查询所有管理员
    public List<Admin> selectAll() throws Exception;
}
