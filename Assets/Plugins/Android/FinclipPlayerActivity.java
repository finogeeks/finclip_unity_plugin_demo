package com.finogeeks.club;

import android.os.Bundle;
import android.widget.Toast;

import com.finogeeks.lib.applet.client.FinAppClient;
import com.finogeeks.lib.applet.client.FinAppConfig;
import com.finogeeks.lib.applet.interfaces.FinCallback;
import com.finogeeks.lib.applet.sdk.api.request.IFinAppletRequest;
import com.unity3d.player.UnityPlayerActivity;

import java.util.HashMap;
import java.util.Map;

public class FinclipPlayerActivity extends UnityPlayerActivity
{

    @Override protected void onCreate(Bundle savedInstanceState)
    {

        super.onCreate(savedInstanceState);

        //init finclip
        System.out.println("start to init finlcip sdk");
        FinAppConfig config = new FinAppConfig.Builder()
                .setAppKey("22LyZEib0gLTQdU3MUauAbdAy0lL3+wYQ2qWJM71nJA=")
                .setAppSecret("16c31e3fc3db24a9")
                .setApiUrl("https://api.finclip.com")
                .setApiPrefix("/api/v1/mop/")
                .setGlideWithJWT(false)
                .build();
        FinCallback<Object> callback = new FinCallback<Object>() {
            @Override
            public void onSuccess(Object result) {
                // SDK初始化成功
                Toast.makeText(FinclipPlayerActivity.this, "SDK初始化成功", Toast.LENGTH_SHORT).show();
            }

            @Override
            public void onError(int code, String error) {
                // SDK初始化失败
                Toast.makeText(FinclipPlayerActivity.this, "SDK初始化失败", Toast.LENGTH_SHORT).show();
            }

            @Override
            public void onProgress(int status, String error) {
                Toast.makeText(FinclipPlayerActivity.this, "SDK初始化中。。。。。。", Toast.LENGTH_SHORT).show();
            }
        };
        FinAppClient.INSTANCE.init(this.getApplication(), config, callback);
    }

    public void appletStart(String appId) {
        System.out.println("appletStart appId" + appId);
        Map<String, String> params = new HashMap<>();
        FinAppClient.INSTANCE.getAppletApiManager()
                .startApplet(this, IFinAppletRequest.Companion
                        .fromAppId(appId)
                        .setStartParams(params), null);
    }
}
