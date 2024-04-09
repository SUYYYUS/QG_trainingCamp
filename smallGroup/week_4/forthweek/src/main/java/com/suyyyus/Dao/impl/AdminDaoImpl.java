package com.suyyyus.Dao.impl;

import com.suyyyus.Dao.AdminDao;
import com.suyyyus.pojo.Admin;
import com.suyyyus.utils.CRUDUtilsAdmin;

import java.util.List;

/**
 * 实现AdminDao接口的方法
 */
public class AdminDaoImpl implements AdminDao {

    /**
     * 进行登录
     * @param adminname
     * @return
     * @throws Exception
     */
    @Override
    public boolean checkAdmin(String adminname, String password) throws Exception {

        String sql = "select * from tb_admin where adminname = ? and password = ?";
        if(CRUDUtilsAdmin.checkAdmin(sql,adminname,password)){
            return true;
        }else {
            return false;
        }
    }


    /**
     * 查看所有管理员的信息
     * @return
     * @throws Exception
     */
    @Override
    public List<Admin> selectAll() throws Exception {
        String sql = "select * from tb_admin";
        List<Admin> list = CRUDUtilsAdmin.queryAll(sql);
        return list;
    }

}
