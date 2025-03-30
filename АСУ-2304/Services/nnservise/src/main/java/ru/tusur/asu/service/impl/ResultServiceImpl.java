package ru.tusur.asu.service.impl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ru.tusur.asu.model.Result;
import ru.tusur.asu.repository.ResultRepository;
import ru.tusur.asu.service.ResultService;

import java.util.List;

@Service
public class ResultServiceImpl implements ResultService {

    @Autowired
    private ResultRepository resultRepository;

    @Override
    public void create(Result result) {
        resultRepository.save(result);
    }

    @Override
    public List<Result> readAll() {
        return resultRepository.findAll();
    }

    @Override
    public Result read(Integer id) {
        return resultRepository.getReferenceById(id);
    }

    @Override
    public boolean update(Result result, Integer id) {
        if (!resultRepository.existsById(id)) {
            return false;
        }

        result.setId(id);
        resultRepository.save(result);

        return true;
    }

    @Override
    public boolean delete(Integer id) {
        if (!resultRepository.existsById(id)) {
            return false;
        }

        resultRepository.deleteById(id);

        return true;
    }
}
