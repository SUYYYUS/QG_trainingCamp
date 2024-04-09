package com.suyyyus.service.impl;

import com.suyyyus.Dao.UserDao;
import com.suyyyus.Dao.impl.UserDaoImpl;
import com.suyyyus.pojo.PageBean;
import com.suyyyus.pojo.User;
import com.suyyyus.service.UserService;

import java.util.List;

public class UserServiceImpl implements UserService {

    UserDao userDao = new UserDaoImpl();

    /**
     * 添加用户
     * @param user
     */
    @Override
    public void insertUser(User user) {
        //调用Dao层方法
        userDao.insertUser(user);
    }

    @Override
    public void deleteUser(int id) {

    }

    @Override
    public void deleteUsers(int[] id) {

    }

    @Override
    public void updateinfo(User user) {

    }

    @Override
    public List<User> queryAll() {
        return null;
    }

    @Override
    public List<User> queryById(int id) throws Exception {
        return null;
    }

    /**
     * 分页查询
     * @param currentPage
     * @param pageSize
     * @return
     * @throws Exception
     */
    @Override
    public PageBean<User> selectByPage(int currentPage, int pageSize) throws Exception {
        //开始索引
        int begin = (currentPage - 1) * pageSize;
        //页数
        int size = pageSize;

        //当前页数据
        List<User> rows = userDao.selectByPage(begin, size);

        //查询总记录数
        int count = userDao.selectAllCount();

        //封装pageBean对象
        PageBean<User> pageBean = new PageBean<>();
        pageBean.setRows(rows);
        pageBean.setTotalCount(count);

        return pageBean;
    }

    @Override
    public List<User> queryByPassword(String password) throws Exception {
        return null;
    }

    /**
     * 用户登录
     * @param username
     * @param paaword
     * @return
     * @throws Exception
     */
    @Override
    public boolean userLogin(String username, String paaword) throws Exception {
        boolean b = userDao.userLogin(username, paaword);
        return b;
    }


    @Override
    public boolean checkUsername(String username) throws Exception {
        boolean b = userDao.checkUsername(username);
        return b;
    }


    /**
     * 通过用户名查询信息
     * @param username
     * @return
     */
    @Override
    public User queryByUsername(String username) throws Exception {
        User user = userDao.queryByUsername(username);
        return user;
    }

    @Override
    public User confirmByCardid(String cardid) throws Exception {
        User b = userDao.confirmByCardid(cardid);
        return b;
    }


    @Override
    public void resetPassword(String cardid) {
        userDao.resetPassword(cardid);
    }
}
