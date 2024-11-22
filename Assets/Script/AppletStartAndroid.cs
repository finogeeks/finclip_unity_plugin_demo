using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class AppletStart : MonoBehaviour
{
    public void OnButtonClick()
    {
        Debug.Log("start OnButtonClick");

        AndroidJavaClass jclass = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
        AndroidJavaObject jcontext = jclass.GetStatic<AndroidJavaObject>("currentActivity");
        jcontext.Call("appletStart", "60dacf37a2b11b0001c43a17");

        Debug.Log("done appletStart ");
    }
}