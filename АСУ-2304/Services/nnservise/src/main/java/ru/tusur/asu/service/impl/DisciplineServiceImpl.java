package ru.tusur.asu.service.impl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ru.tusur.asu.model.Discipline;
import ru.tusur.asu.repository.DisciplineRepository;
import ru.tusur.asu.service.DisciplineService;

import java.util.List;

@Service
public class DisciplineServiceImpl implements DisciplineService {

    @Autowired
    private DisciplineRepository disciplineRepository;

    @Override
    public void create(Discipline discipline) {
        disciplineRepository.save(discipline);
    }

    @Override
    public List<Discipline> readAll() {
        return disciplineRepository.findAll();
    }

    @Override
    public Discipline read(Integer id) {
        return disciplineRepository.getReferenceById(id);
    }

    @Override
    public boolean update(Discipline discipline, Integer id) {
        if (!disciplineRepository.existsById(id)) {
            return false;
        }

        discipline.setId(id);
        disciplineRepository.save(discipline);

        return true;
    }

    @Override
    public boolean delete(Integer id) {
        if (!disciplineRepository.existsById(id)) {
            return false;
        }

        disciplineRepository.deleteById(id);

        return true;
    }
}
