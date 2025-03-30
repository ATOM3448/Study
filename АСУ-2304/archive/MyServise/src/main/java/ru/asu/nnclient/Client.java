package ru.asu.nnclient;

import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;

public class Client {
    public static void main(String[] args) throws IOException, URISyntaxException, InterruptedException {

        HttpClient test = HttpClient.newBuilder().build();
        HttpResponse<Object> send = test.send(HttpRequest.newBuilder().GET().uri(new URI("http://localhost:8999/api/studydatabase")).build(), responseInfo -> {
            System.out.println(responseInfo.statusCode());
            return null;
        });
    }
}
