package com.suyyyus.Dao;

import com.suyyyus.pojo.User;

import java.util.List;
/**
 * 接口
 */
public interface UserDao {

    //添加用户
    public int insertUser(User user);

    //删除信息（根据id）
    public int deleteUser(int id);

    //修改信息（根据ID）
    public int updateinfo(User user);

    //查询全部信息
    public void queryAll();

    //查询某个信息
    public void queryById(int id);
}
