package ru.tusur.asu.service;

import ch.qos.logback.core.net.server.Client;
import ru.tusur.asu.model.Organization;

import java.util.List;

public interface Service<T> {
    void create(T organization);

    List<T> readAll();

    T read(Integer id);

    boolean update(T client, Integer id);

    boolean delete(Integer id);
}
