package ru.tusur.asu.service.impl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ru.tusur.asu.model.Indicator;
import ru.tusur.asu.repository.IndicatorRepository;
import ru.tusur.asu.service.IndicatorService;

import java.util.List;

@Service
public class IndicatorServiceImpl implements IndicatorService {

    @Autowired
    private IndicatorRepository indicatorRepository;

    @Override
    public void create(Indicator indicator) {
        indicatorRepository.save(indicator);
    }

    @Override
    public List<Indicator> readAll() {
        return indicatorRepository.findAll();
    }

    @Override
    public Indicator read(Integer id) {
        return indicatorRepository.getReferenceById(id);
    }

    @Override
    public boolean update(Indicator indicator, Integer id) {
        if (!indicatorRepository.existsById(id)) {
            return false;
        }

        indicator.setId(id);
        indicatorRepository.save(indicator);

        return true;
    }

    @Override
    public boolean delete(Integer id) {
        if (!indicatorRepository.existsById(id)) {
            return false;
        }

        indicatorRepository.deleteById(id);

        return true;
    }
}
