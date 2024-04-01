package com.suyyyus.Dao;

import com.suyyyus.pojo.User;

import java.util.List;
/**
 * 接口
 */
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
}
