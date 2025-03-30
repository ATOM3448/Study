package ru.tusur.asu.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import ru.tusur.asu.model.Indicator;
import ru.tusur.asu.service.IndicatorService;

import java.util.List;

@RestController
public class IndicatorController {
    private static final String mapping = "/api/indicators";

    private final IndicatorService indicatorService;

    @Autowired
    public IndicatorController(IndicatorService indicatorService) {
        this.indicatorService = indicatorService;
    }

    @GetMapping(value = mapping + "/{id}")
    public ResponseEntity<Indicator> read(@PathVariable(name = "id") int id) {
        final Indicator indicator = indicatorService.read(id);

        return indicator != null
                ? new ResponseEntity<>(indicator, HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_FOUND);
    }

    @GetMapping(value = mapping)
    public ResponseEntity<List<Indicator>> readAll() {
        final List<Indicator> indicators = indicatorService.readAll();

        return indicators != null && !indicators.isEmpty()
                ? new ResponseEntity<>(indicators, HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_FOUND);
    }

    @PostMapping(value = mapping)
    public ResponseEntity<?> create(@RequestBody Indicator indicator) {
        indicatorService.create(indicator);
        return new ResponseEntity<>(HttpStatus.CREATED);
    }

    @PutMapping(value = mapping + "/{id}")
    public ResponseEntity<?> update(@PathVariable(name = "id") int id,
                                    @RequestBody Indicator indicator) {
        final boolean updated = indicatorService.update(indicator, id);

        return updated
                ? new ResponseEntity<>(HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_MODIFIED);
    }

    @DeleteMapping(value = mapping + "/{id}")
    public ResponseEntity<?> delete(@PathVariable(name = "id") int id) {
        final boolean deleted = indicatorService.delete(id);

        return deleted
                ? new ResponseEntity<>(HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_MODIFIED);
    }
}
