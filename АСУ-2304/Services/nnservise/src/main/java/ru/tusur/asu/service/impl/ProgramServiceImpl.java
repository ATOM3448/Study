package ru.tusur.asu.service.impl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ru.tusur.asu.model.Program;
import ru.tusur.asu.repository.ProgramRepository;
import ru.tusur.asu.service.ProgramService;

import java.util.List;

@Service
public class ProgramServiceImpl implements ProgramService {

    @Autowired
    private ProgramRepository programRepository;

    @Override
    public void create(Program program) {
        programRepository.save(program);
    }

    @Override
    public List<Program> readAll() {
        return programRepository.findAll();
    }

    @Override
    public Program read(Integer id) {
        return programRepository.getReferenceById(id);
    }

    @Override
    public boolean update(Program program, Integer id) {
        if (!programRepository.existsById(id)) {
            return false;
        }

        program.setId(id);
        programRepository.save(program);

        return true;
    }

    @Override
    public boolean delete(Integer id) {
        if (!programRepository.existsById(id)) {
            return false;
        }

        programRepository.deleteById(id);

        return true;
    }
}
