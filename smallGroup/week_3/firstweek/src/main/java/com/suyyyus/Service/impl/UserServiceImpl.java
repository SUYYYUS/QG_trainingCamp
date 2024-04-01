package com.suyyyus.Service.impl;

import com.suyyyus.Dao.UserDao;
import com.suyyyus.Dao.impl.UserDaoImpl;
import com.suyyyus.Service.UserService;
import com.suyyyus.pojo.PageBean;
import com.suyyyus.pojo.User;

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

    /**
     * 根据id删除用户信息
     * @param id
     */
    @Override
    public void deleteUser(int id) {
        userDao.deleteUser(id);
    }

    /**
     * 批量删除用户信息通过他们的ID
     *
     * @param id
     */
    @Override
    public void deleteUsers(int[] id) {
        userDao.deleteUsers(id);
    }

    /**
     * 修改用户信息
     * @param user
     */
    @Override
    public void updateinfo(User user) {
        userDao.updateinfo(user);
    }

    /**
     * 查询所有用户信息
     * @return
     */
    @Override
    public List<User> queryAll() {
        List<User> list = userDao.queryAll();
        return list;
    }

    /**
     * 通过id查询用户信息
     * @param id
     */
    @Override
    public List<User> queryById(int id) throws Exception {
        List<User> list = userDao.queryById(id);
        return list;
    }


    /**
     * 分页查询
     * @param currentPage 当前的页面数，开始索引
     * @param pageSize 页数的条数
     * @return PageBean 封装对象
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
}
