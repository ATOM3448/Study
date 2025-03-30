package ru.asu.nnservise;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.IOException;
import java.net.InetSocketAddress;

import com.sun.net.httpserver.HttpServer;
import ru.asu.nnservise.model.StudyHttpHandler;

public class Service {
    private static final Logger logger = LoggerFactory.getLogger(Service.class);

    private static final int PORT = 8999;

    public static void main(String[] args) throws IOException {
        HttpServer server = HttpServer.create(new InetSocketAddress(PORT), 0);

        server.createContext("/api/studydatabase", new StudyHttpHandler());

        server.setExecutor(null);
        server.start();
        logger.info("Сервер запущен.");
    }
}