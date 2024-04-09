package com.suyyyus.service.impl;

import com.suyyyus.Dao.AdminDao;
import com.suyyyus.Dao.impl.AdminDaoImpl;
import com.suyyyus.pojo.Admin;
import com.suyyyus.service.AdminService;

import java.util.List;

public class AdminServiceImpl implements AdminService {

    AdminDao adminDao = new AdminDaoImpl();

    /**
     * 登录操作
     * @param adminname 管理员名
     * @param password 密码
     * @return 成功或失败
     * @throws Exception
     */
    @Override
    public boolean checkAdmin(String adminname,String password) throws Exception {
        if(adminDao.checkAdmin(adminname, password)){
            return true;
        }
        return false;
    }

    /**
     * 查看所有管理员信息
     * @return
     * @throws Exception
     */
    @Override
    public List<Admin> queryAll() throws Exception {
        List<Admin> admins = adminDao.selectAll();
        return admins;
    }

}
