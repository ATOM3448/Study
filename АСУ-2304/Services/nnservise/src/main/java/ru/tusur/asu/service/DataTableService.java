package ru.tusur.asu.service;

import java.util.List;

public interface DataTableService<T> {
    void create(T organization);

    List<T> readAll();

    T read(Integer id);

    boolean update(T client, Integer id);

    boolean delete(Integer id);
}
