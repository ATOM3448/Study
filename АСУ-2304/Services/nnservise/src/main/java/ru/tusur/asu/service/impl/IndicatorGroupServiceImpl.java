package ru.tusur.asu.service.impl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ru.tusur.asu.model.IndicatorGroup;
import ru.tusur.asu.repository.IndicatorGroupRepository;
import ru.tusur.asu.service.IndicatorGroupService;

import java.util.List;

@Service
public class IndicatorGroupServiceImpl implements IndicatorGroupService {

    @Autowired
    private IndicatorGroupRepository indicatorGroupRepository;

    @Override
    public void create(IndicatorGroup indicatorGroup) {
        indicatorGroupRepository.save(indicatorGroup);
    }

    @Override
    public List<IndicatorGroup> readAll() {
        return indicatorGroupRepository.findAll();
    }

    @Override
    public IndicatorGroup read(Integer id) {
        return indicatorGroupRepository.getReferenceById(id);
    }

    @Override
    public boolean update(IndicatorGroup indicatorGroup, Integer id) {
        if (!indicatorGroupRepository.existsById(id)) {
            return false;
        }

        indicatorGroup.setId(id);
        indicatorGroupRepository.save(indicatorGroup);

        return true;
    }

    @Override
    public boolean delete(Integer id) {
        if (!indicatorGroupRepository.existsById(id)) {
            return false;
        }

        indicatorGroupRepository.deleteById(id);

        return true;
    }
}
