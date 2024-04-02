package com.suyyyus.Service;


import com.suyyyus.pojo.PageBean;
import com.suyyyus.pojo.User;

import java.util.List;

/**
 * 用户表的Service接口
 */
public interface UserService {

    //添加用户
    public void insertUser(User user);

    //删除信息（根据id）
    public void deleteUser(int id);

    //批量删除信息（根据id）
    public void deleteUsers(int[] id);

    //修改信息（根据ID）
    public void updateinfo(User user);

    //查询全部信息
    public List<User> queryAll() ;

    //查询某个信息
    public List<User> queryById(int id) throws Exception;


    //分页查询
    PageBean<User> selectByPage(int begin, int size) throws Exception;

    //通过密码进行模糊查询
    public List<User> queryByPassword(String password) throws Exception;
}
