package com.suyyyus.Dao;

import com.suyyyus.pojo.User;

import java.util.List;

public interface UserDao {

    //添加用户
    public void insertUser(User user);

    //删除信息（根据id）
    public void deleteUser(int id);

    //批量删除信息（根据id）
    public void deleteUsers(int[] id);

    //修改信息（根据ID）
    public int updateinfo(User user);

    //查询全部信息
    public List<User> queryAll() ;

    //查询某个信息
    public List<User> queryById(int id) throws Exception;

    //分页查询
    public List<User> selectByPage(int begin, int size);

    //计算数据总条数
    public int selectAllCount() throws Exception;

    //通过密码内容进行模糊查询
    public List<User> queryByAddress(String address) throws Exception;

    //用户登录
    public boolean userLogin(String username, String password) throws Exception;

    //判断用户名是否存在
    public boolean checkUsername(String username) throws Exception;

    //通过名字查询信息
    public User queryByUsername(String username) throws Exception;

    //密码确认
    public User confirmByCardid(String password) throws Exception;

    //重置密码
    public void resetPassword(String cardid);

}
