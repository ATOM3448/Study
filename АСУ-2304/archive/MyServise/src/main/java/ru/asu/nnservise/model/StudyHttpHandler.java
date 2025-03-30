package ru.asu.nnservise.model;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.SerializationFeature;
import com.sun.net.httpserver.HttpExchange;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public final class StudyHttpHandler extends BaseHttpHandler {
    private static final Logger logger = LoggerFactory.getLogger(StudyHttpHandler.class);


    @Override
    public void handle(HttpExchange exchange) throws IOException {
        switch (exchange.getRequestMethod()) {
            case "GET" -> getRequestMethod(exchange);
            case "PUT" -> putRequestMethod(exchange);
            case "POST" -> postRequestMethod(exchange);
            default -> methodNotAllowed(exchange);
        }


    }

    private void getRequestMethod(HttpExchange exchange) throws IOException {
        logger.info("Get-запрос");
        Map<String, List<String>> params = splitQuery(exchange.getRequestURI().getRawQuery());

        String respText = "Returns data from database\n";

        HashMap<String, HashMap<String, HashMap<String, Integer>>> student = new HashMap<>();
        HashMap<String, HashMap<String, Integer>> discipline = new HashMap<>();
        HashMap<String, Integer> indicator = new HashMap<>();
        indicator.put("kt1", 4);
        indicator.put("kt2", 2);
        indicator.put("exam", 5);
        discipline.put("Math", indicator);
        indicator = new HashMap<>();
        indicator.put("kt1", 4);
        indicator.put("kt2", 4);
        indicator.put("exam", 5);
        indicator.put("lab1", 3);
        discipline.put("PP", indicator);
        student.put("Volodya", discipline);

        ObjectMapper mapper = new ObjectMapper();
        mapper.enable(SerializationFeature.INDENT_OUTPUT);
        respText = mapper.writeValueAsString(student);

        send(exchange, 200, respText);
    }

    private void putRequestMethod(HttpExchange exchange) throws IOException {
        Map<String, List<String>> params = splitQuery(exchange.getRequestURI().getRawQuery());

        String respText = "Write data into database\n";

        send(exchange, 201, respText);
    }

    private void postRequestMethod(HttpExchange exchange) throws IOException {
        Map<String, List<String>> params = splitQuery(exchange.getRequestURI().getRawQuery());

        String respText = "Launch neuronet on your data\n";

        send(exchange, 202, respText);
    }
}
