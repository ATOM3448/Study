package ru.tusur.asu.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import ru.tusur.asu.model.Program;
import ru.tusur.asu.service.ProgramService;

import java.util.List;

@RestController
public class ProgramController {
    private static final String mapping = "/api/programs";

    private final ProgramService programService;

    @Autowired
    public ProgramController(ProgramService programService) {
        this.programService = programService;
    }

    @GetMapping(value = mapping + "/{id}")
    public ResponseEntity<Program> read(@PathVariable(name = "id") int id) {
        final Program program = programService.read(id);

        return program != null
                ? new ResponseEntity<>(program, HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_FOUND);
    }

    @GetMapping(value = mapping)
    public ResponseEntity<List<Program>> readAll() {
        final List<Program> programs = programService.readAll();

        return programs != null && !programs.isEmpty()
                ? new ResponseEntity<>(programs, HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_FOUND);
    }

    @PostMapping(value = mapping)
    public ResponseEntity<?> create(@RequestBody Program program) {
        programService.create(program);
        return new ResponseEntity<>(HttpStatus.CREATED);
    }

    @PutMapping(value = mapping + "/{id}")
    public ResponseEntity<?> update(@PathVariable(name = "id") int id,
                                    @RequestBody Program program) {
        final boolean updated = programService.update(program, id);

        return updated
                ? new ResponseEntity<>(HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_MODIFIED);
    }

    @DeleteMapping(value = mapping + "/{id}")
    public ResponseEntity<?> delete(@PathVariable(name = "id") int id) {
        final boolean deleted = programService.delete(id);

        return deleted
                ? new ResponseEntity<>(HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_MODIFIED);
    }
}
